Add detection for '/' before string end (>) in the while(isalpha) loop (line 31 of part1Main.c), if its true then just ignore the standalone tag.

To run pt 1:
echo "<a><b></b></a>" > test.txt
./validateXML < test.txt

also ./validateXML < test.txt > out.txt if you wanna redirect stdout

To run pt 2:
echo -e "15\n20\n10\n3" > testheap.txt
./heap < testheap.txt

stdout only:
echo -e "15\n20\n10\n3" | ./heap > out.txt

stderr only:
echo -e "15\n20\n10\n3" | ./heap 2> err.txt


>
2>
2>&1
