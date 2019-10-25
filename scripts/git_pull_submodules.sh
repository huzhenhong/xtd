#!/bin/bash

git submodule update --init

declare -a submodules=("xtd.tunit")

for submodule in ${submodules[@]}; do
  cd src/$submodule
  git pull origin master
  cd ../..
done
