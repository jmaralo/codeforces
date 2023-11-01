#! /bin/bash

new() {
    if [ "$#" -ne 1 ]; then
        echo "Please provide problem id"
        return 1
    fi

    problem=$1
    letter=${problem:(-1)}
    number=${problem:0:(-1)}

    mkdir -p "$number/$letter"
    cp template.cpp "$number/$letter/$letter.cpp"

    touch "$number/$letter/in"
    touch "$number/$letter/out"

    echo "Created folder for exercise $problem!"
    echo "Make sure to copy the example input and output"
}

check() {
    if [ "$#" -ne 1]; then
        echo "Please provide problem id"
        return 1
    fi

    problem=$1
    letter=${problem:(-1)}
    number=${problem:0:(-1)}

    set -e

    cd "$number/$letter"

    g++ -std=c++17 "$letter.cpp" -o "$letter.out"
    ./"$letter.out" <"in" >"tmp"

    echo "Diff: (got | expected)"

    diff "tmp" "out"

    rm "tmp"

    echo "Done!"
}

export new
export check