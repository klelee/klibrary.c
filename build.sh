#!/bin/bash

build_dir=out

if [ -d ${build_dir} ];then
    rm -rf ${build_dir}
fi

mkdir ${build_dir}

cd ${build_dir}

cmake ..

make -j8
