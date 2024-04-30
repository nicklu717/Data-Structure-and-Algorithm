commands=(
    "git submodule init"
    "git submodule update"
    "./tools/vcpkg/bootstrap-vcpkg.sh"
    "./tools/vcpkg/vcpkg install gtest"
)

for command in "${commands[@]}"; do
    echo "======== Executing command: \`$command\` ========"
    $command
    echo "======== Finished command: \`$command\` ========\n"
done