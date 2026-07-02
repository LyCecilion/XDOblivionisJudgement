set positional-arguments

default:
    just --list

list:
    ./tools/oj list

add id:
    ./tools/oj add {{ id }}

add-c id:
    ./tools/oj add -c {{ id }}

build id mode="debug":
    ./tools/oj build {{ id }} {{ mode }}

run id mode="debug":
    ./tools/oj run {{ id }} {{ mode }}

test id mode="debug":
    ./tools/oj test {{ id }} {{ mode }}

check id:
    ./tools/oj check {{ id }}

fmt target="":
    ./tools/oj fmt {{ target }}

tidy target:
    ./tools/oj tidy {{ target }}

bench id:
    ./tools/oj bench {{ id }}

memcheck id:
    ./tools/oj memcheck {{ id }}

sync-list:
    ./tools/oj sync-list

clean id="":
    ./tools/oj clean {{ id }}
