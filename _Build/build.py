# coding=utf-8

# modules
import os

# variables
outpath = "./out.md"
endl = "\n\n"

# write to target
def print_to_md(target, codepath):
    codes = open(codepath, mode="r", encoding="utf8")
    target.write("```cpp" + endl + codes.read() + "```" + endl)
    codes.close()

# main
def main():
    # check old
    if os.path.exists(outpath):
        os.remove(outpath)

    # create out.md
    target = open(outpath, mode="w", encoding="utf8")
    target.write("# 目录\n\n[TOC]\n\n")

    # get dirs
    template_dirs = os.listdir("..")

    # get templatefiles
    now = 1
    for dir in template_dirs:
        # for every genres
        if dir[0] == str(now):
            now += 1
            target.write("# " + dir + endl)

            for file in os.listdir("../" + dir):
                # if it's a binary file
                if (
                    file.endswith(".exe")
                    or file.endswith(".out")
                    or file.endswith(".o")
                    or file.endswith(".md")
                ):
                    continue
                # if is code
                else:
                    target.write("## " + file + endl)
                    print_to_md(target, "../" + dir + "/" + file)
    target.close()

if __name__ == "__main__":
    main()
pass
