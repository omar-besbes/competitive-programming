# 1. creating the executables
g++ brute.cpp -o brute_executable
g++ optimal.cpp -o optimal_executable

# 2. getting the number of times to run the script from command line args
n=$1

# --------------------- 3 ------------------------------- #
# running loop for n times (N files)
for (( i=1; i<=n; ++i ))
do
    python testcase.py # generate and map testcases to testcase.txt
    
    # generate and map respective outputs
    ./brute_executable < testcase.txt > brute_out.txt
    ./optimal_executable < testcase.txt > optimal_out.txt
    
    # Bash Magic 🤩 : If the difference command produces any output
    if [[ $(diff brute_out.txt optimal_out.txt) ]]
    then
        # 🤩 map the output of diff command to difference_file
        echo "$(diff -Z brute_out.txt optimal_out.txt)" > difference_file.txt
    
        echo "Difference reported in file difference_file.txt"
        echo "--------------------------------------------------------"
        echo "You Can find the testcase where your optimal solution failed in testcase.txt and the respective outputs in brute_out.txt and optimal_out.txt"
        
        # 🤐 Once the difference is found and we've reported it then no need to generate extra testcases we can break right here
        break
    else
        echo "AC on super-test $i"
    fi
done

# 👌 When the program passes all the test files
echo "--------------Testing done-----------"