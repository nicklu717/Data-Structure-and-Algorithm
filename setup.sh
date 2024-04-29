git submodule init && \
git submodule update && \
./tools/vcpkg/bootstrap-vcpkg.sh && \
./tools/vcpkg/vcpkg install gtest