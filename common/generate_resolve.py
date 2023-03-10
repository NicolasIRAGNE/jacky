template = "\tcase X:\n\
\t\topcode_impl<X>();\n\
\t\tbreak;"

for i in range(1, 0xff):
    # keep the hex value in the range of 0x00 to 0xff
    print(template.replace("X", hex(i)))