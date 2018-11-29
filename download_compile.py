import os
rm_old = "rm -rf eprog-master/"
download = "wget -P ./ https://www.github.com/Cetzcher/eprog/archive/master.zip"
unzip = "unzip master.zip"
rm_zip = "rm master.zip"
base_path = "eprog-master/"
compiled = base_path + "compiled/"

def main(): 
    os.system(rm_old)
    print("\033[1;32;40m Removed Old Dir  \033[0m\n")
    print("\033[1;34;40m Running Wget\n")
    os.system(download)
    print("\033[0m")
    print("\033[1;32;40m Downloaded Archive  \033[0m\n")
    os.system(unzip)
    print("\033[1;32;40m Unzipping Archive  \033[0m\n")
    os.system(rm_zip)
    print("\033[1;32;40m Removed Old Archive  \033[0m\n")
    
    print("Creating executeables")
    os.mkdir(compiled)

    compiled_files = 0
    _, dirs,__ = next(os.walk(base_path))
    for d in dirs: 
        compiled_dir = compiled + d
        
        if d != "compiled" and d != ".vscode":
            print "Creating dir: ", compiled + d
            os.mkdir(compiled + d)
            _, _, files = next(os.walk(base_path + d))
            for f in files: 
                if f.endswith(".c"):
                    print "    \033[1;32;40mcompiling file:{0}\033[m".format(f) 
                    compiled_files += 1
                    os.system("gcc {0} -lm -o {1} ".format(base_path + d + "/" + f, compiled_dir + "/" + f[0:-2] + ".out"))   


main()