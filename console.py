#!/usr/bin/python3

"""
This module is the cmd interface for the console

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 07/08/2023
"""


import models
import cmd
from re import findall, search, VERBOSE
from models.base_model import BaseModel
from models.user import User
from models.state import State
from models.city import City
from models.place import Place
from models.amenity import Amenity
from models.review import Review


class HBNBCommand(cmd.Cmd):
    """Customized simple command line interpreter using Cmd class"""

    prompt = "(hbnb) "
    __class_names = {"BaseModel", "User", "State", "City", "Place",
                     "Amenity", "Review"}

    def precmd(self, line):
        """Handles command processing before it is accepted by a function
        """
        args = findall(r"\S+\.\S+\(.*\)", line)
        arglen = len(args)
        pattern = r"\w+\.all\(\s*\)"
        pattern2 = r"\w+\.count\(\s*\)"
        pattern3 = r"\w+\.show\(.*\)"
        pattern4 = r"\w+\.destroy\(.*\)"
        pattern5 = r"\w+\.update\(.*\)"

        if arglen >= 1 and search(pattern, args[0]):
            clsmatch = search(r"\w+(?=\.all\(\s*\))", args[0])
            return f"all {clsmatch.group()}"
        elif arglen >= 1 and search(pattern2, args[0]):
            clsmatch = search(r"\w+(?=\.count\(\s*\))", args[0])
            return f"count {clsmatch.group()}"
        elif arglen >= 1 and search(pattern3, args[0]):
            clsmatch = search(r"\w+(?=\.show\(.*\))", args[0])
            p1 = r"""(?<=\.show\(\")[^\"]+(?=\"\))|
            (?<=\.show\(\')[^\']+(?=\'\))|
            (?<=\.show\()[^\'\"]+(?=\))
            """
            idmatch = search(p1, args[0], VERBOSE)
            if idmatch is None:
                return f"show {clsmatch.group()}"
            return f"show {clsmatch.group()} {idmatch.group()}"
        elif arglen >= 1 and search(pattern4, args[0]):
            clsmatch = search(r"\w+(?=\.destroy\(.*\))", args[0])
            p1 = r"""(?<=\.destroy\(\")[^\"]+(?=\"\))|
            (?<=\.destroy\(\')[^\']+(?=\'\))|
            (?<=\.destroy\()[^\'\"]+(?=\))
            """
            idmatch = search(p1, args[0], VERBOSE)
            if idmatch is None:
                return f"destroy {clsmatch.group()}"
            return f"destroy {clsmatch.group()} {idmatch.group()}"
        elif arglen >= 1 and search(pattern5, args[0]):
            cm = search(r"\w+(?=\.update\(.*\))", args[0])
            idstr = r"""(?<=\.update\(\")[^\"]*(?=\",)|
            (?<=\.update\(\')[^\']*(?=\',)|
            (?<=\.update\()[^\'\"]*(?=,)
            """
            namestr = r"""(?<=,\s\")[^\"]*(?=\",)|
            (?<=,\s\')[^\']*(?=\',)|
            (?<=,\s)[^\'\"]*(?=,)
            """
            valuestr = r"""(?<=,\s\")[^\"]*(?=\"\))|
            (?<=,\s\')[^\']*(?=\'\))|
            (?<=,\s)[^\'\"]*(?=\))
            """
            idmatch = search(idstr, args[0], VERBOSE)
            namematch = search(namestr, args[0], VERBOSE)
            valuematch = search(valuestr, args[0], VERBOSE)
            if idmatch is None:
                return f"update {cm.group()}"
            elif idmatch and namematch is None:
                return f"update {cm.group()} {idmatch.group()}"
            elif idmatch and namematch and valuematch is None:
                return f"""update {cm.group()} {idmatch.group()} \
                {namematch.group()}"""
            else:
                return f"""update {cm.group()} {idmatch.group()} \
                {namematch.group()} {valuematch.group()}"""
        else:
            return line

    def do_count(self, line):
        """counts the number of instances of a specific class
        """
        args = line.split()
        sum = 0
        dict_obj = models.storage.all()

        if len(args) == 1 and args[0] in HBNBCommand.__class_names:
            for obj in dict_obj.values():
                if str(obj).startswith(f"[{args[0]}]"):
                    sum += 1
            print(sum)

    def do_EOF(self, line):
        """Handles EOF signal by exiting the Shell
        """
        print()
        return True

    def do_quit(self, line):
        """Quit command to exit the program
        """
        return True

    def do_create(self, line):
        """Creates new instance  and saves it to file
        """
        args = line.split()
        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.__class_names:
            print("** class doesn't exist **")
        else:
            objstr = f"{args[0]}()"
            obj = eval(objstr)
            obj.save()
            print(obj.id)

    def do_show(self, line):
        """Displays string representing object id and and object dictionary
        """
        dict_obj = models.storage.all()
        args = line.split()
        arglen = len(args)
        if arglen == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.__class_names:
            print("** class doesn't exist **")
        elif arglen < 2:
            print("** instance id missing **")
        elif f"{args[0]}.{args[1]}" not in dict_obj.keys():
            print("** no instance found **")
        else:
            print(dict_obj[f"{args[0]}.{args[1]}"])

    def do_destroy(self, line):
        """Deletes instance based on class name and id
        """
        dict_obj = models.storage.all()
        args = line.split()
        arglen = len(args)

        if arglen == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.__class_names:
            print("** class doesn't exist **")
        elif arglen < 2:
            print("** instance id missing **")
        elif f"{args[0]}.{args[1]}" not in dict_obj.keys():
            print("** no instance found **")
        else:
            del dict_obj[f"{args[0]}.{args[1]}"]

        models.storage.save()

    def do_all(self, line):
        """Prints list of string representations of an object
        """
        dict_obj = models.storage.all()
        args = line.split()
        arglen = len(args)
        obj_list = []

        if arglen >= 1 and args[0] not in HBNBCommand.__class_names:
            print("** class doesn't exist **")
        else:
            for val in dict_obj.values():
                if arglen >= 1 and val.__class__.__name__ == args[0]:
                    obj_list.append(str(val))
                elif arglen == 0:
                    obj_list.append(str(val))
            print(obj_list)

    def do_update(self, line):
        """This updates/adds attributes of an instance of a <class.id>
        """
        dict_obj = models.storage.all()
        # return matches with dquotes, quotes or any nonspace character
        args = findall(r'"[^"]*"|\'[^\']*\'|\S+', line)
        arglen = len(args)

        if arglen == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.__class_names:
            print("** class doesn't exist **")
        elif arglen < 2:
            print("** instance id missing **")
        elif f"{args[0]}.{args[1]}" not in dict_obj.keys():
            print("** no instance found **")
        elif arglen < 3:
            print("** attribute name missing **")
        elif arglen < 4:
            print("** value missing **")
        # ClassName: arg[0] | id: arg[1] | attrname: arg[2] | attrvalue: arg[3]
        else:
            try:
                value = eval(args[3])
                if type(value) not in [int, float, str]:
                    value = args[3]
            except (NameError, SyntaxError, TypeError, ValueError):
                value = args[3]

            setattr(dict_obj[f"{args[0]}.{args[1]}"], args[2], value)
            dict_obj[f"{args[0]}.{args[1]}"].save()

    def emptyline(self):
        """handles the empty line condition
        """
        pass


if __name__ == '__main__':
    HBNBCommand().cmdloop()
