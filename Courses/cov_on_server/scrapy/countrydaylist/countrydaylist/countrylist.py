def main():
    file = open("C:\\Users\\LYYRE-OAO\\Desktop\\c.txt", "r+", encoding = 'utf-8')
    str = file.read()
    str = str.replace("\"\n\"", " ")
    print(str)
    list = str.split(" ")
    print(list)
    str = ""
    for item in list:
        str += "{\'country\': \"" + item + "\"},\n"
    print(str)

if __name__ == '__main__':
    main()
    # print(__name__)


