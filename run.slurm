#!/bin/sh

folder=`date +%y%m%d%H%M%S`
mkdir -p $folder
cd $folder

for i in {0..9}; do
  sed -e "s/V.r/V$i.r/" -e "s/1234/9$i/" \
    -e "s|det|$HOME/geant4/examples/doppler/det|" \
    ../run.mac > $i.mac
  sbatch --wrap="gears $i.mac"
done
