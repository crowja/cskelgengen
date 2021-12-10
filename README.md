# Cskelgengen 0.15.1

Generates skeleton generators for C projects. A code generator that generates code generators ...

## Overview

From the top-level directory run

    $ ./mkskelgen cclass

This will create the binary build/cclassgen using the contents of
skeletons/cclass. Cclassgen can then be moved to wherever. Do

    $ cclassgen -h

for help.

Same for other skeletons, currently capp, copts, cutils. I've found this sort of
thing to be useful for getting started quickly on new projects.

## Skeletons

When run as

    $ ./mkskelgen abc

mkskelgen looks at skeletons/abc/MANIFEST to see what to include. So each
skeleton folder should have at least a MANIFEST. It also needs a HEADER.bash;
see the folders for examples.
