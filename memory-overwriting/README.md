## first, run:
  bash build.sh
it will build prog1 and prog2

prog1 is the ""victim"",
  start bin/prog1 and press `CTRL+Z` when it pause,
 it will stop the program.
  Now, copy the command args( <> ) it was printed by prog1,
    ./prog2 <> <> <>
  and run /bin/prog2 with these args like
    ./bin/prog2 31865  bebe15a7  33

  and run `fg 1` to go to the prog1 process, and press enter
 the string was been modified to "Hello from prog2"

You can run prog1 normally without stop the program, and you will see
  with the string is other.
