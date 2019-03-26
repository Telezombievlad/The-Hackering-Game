mkdir -p bin
nasm -felf64 src/challenges.asm -o challenges.o
gcc -no-pie -c src/md5.c -o md5.o
gcc -no-pie src/freedom.c challenges.o md5.o -o bin/life.out