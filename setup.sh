echo "===== Executing command: `git submodule init` =====" && \
git submodule init && \
echo "===== Finished command: `git submodule init` =====" && \

echo "===== Executing command: `git submodule update` =====" && \
git submodule update && \
echo "===== Finished command: `git submodule update` =====" && \

echo "===== Executing command: `./tools/vcpkg/bootstrap-vcpkg.sh` =====" && \
./tools/vcpkg/bootstrap-vcpkg.sh && \
echo "===== Finished command: `./tools/vcpkg/bootstrap-vcpkg.sh` =====" && \

echo "===== Executing command: `./tools/vcpkg/vcpkg install gtest` =====" && \
./tools/vcpkg/vcpkg install gtest && \
echo "===== Finished command: `./tools/vcpkg/vcpkg install gtest` =====" && \