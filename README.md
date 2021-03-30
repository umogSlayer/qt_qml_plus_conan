## How to run

Add to conan remotes `bincrafters` repository (a well known bunch of people who maintain many different packages that are not part of the conan-central yet.

    conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan

Then build the project like this:

    cd /path/to/this/project
    mkdir build
    cd build
    conan install --build=missing ..
    cmake -DCONAN_USE_CMAKE_GENERATOR=OFF ..

**OR** as a last step (instead of `cmake ...`) to see a less intrusive conan usage

    cmake -DCONAN_USE_CMAKE_GENERATOR=ON ..
