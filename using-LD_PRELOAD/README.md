# The code
This "tests", was been implemented while i was studying
  the LD_PRELOAD and the "dlfcn" lib.
The first test, is more like a stalker, it doesn't change de value
returned by the function.
But the second, changes his value, turning a common "write()" function into
a "write(1, "Hello World!\n", 0);", every time it with is called.

Run test.sh with "bash test.sh" to see what i've been implemented
and run the program with "./program" to see what the program really does.
