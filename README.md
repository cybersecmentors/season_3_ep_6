# season_3_ep_6
Intro to Fuzzing with AFL
# Compilation and Fuzzing

This is simple Proof-of-Concept to walk through fuzzing with AFL

# Requirements
* AFL
* Bash environment

# Installation
```
sudo apt-get install afl
```

# Execution

1. Compile the code using **afl-clang-fast** with ASAN enabled
        ```
        AFL_USE_ASAN=1 afl-clang-fast -o vuln vuln.c
        ```
2. Test the binary by supplying it with user input
        ```
        echo “hi” | ./vuln
        ```
3. Kick off the fuzzer
        ```
        afl-fuzz -i input -o output ./vuln
        ```
4. Feed the crash output back into the binary for additional info
        ```
        ./vuln < output/default/crashes/id:0000*
        ```
# Tips
* If executing on WSL, you may need to overwrite /proc/sys/kernel/core_pattern for AFL to work correctly.
```
sudo su
echo core >/proc/sys/kernel/core_pattern
