#!/usr/bin/python3

"""
This module is the cmd interface for the console

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 07/08/2023
"""

import models
import cmd
from models.base_model import BaseModel


class HBNBCommand(cmd.Cmd):
    """Simple command processor example."""

    prompt = "(hbnb) "
    __class_names = ["BaseModel"]

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
        """Displays string representation of an instance of class using class
        name and id
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
        elif f"{args[0]}.{args[1]}" not in dict_obj:
            print("** no instance found **")
        else:
            print(dict_obj[f"{args[0]}.{args[1]}"])

    def do_destroy(self, line):
        """Deletes instance based on class name and id"""
        dict_obj = models.storage.all()
        args = line.split()
        arglen = len(args)

        if arglen == 0:
            print("** class name missing **")
        elif args[0] not in HBNBCommand.__class_names:
            print("** class doesn't exist **")
        elif arglen < 2:
            print("** instance id missing **")
        elif f"{args[0]}.{args[1]}" not in dict_obj:
            print("** no instance found **")
        else:
            del dict_obj[f"{args[0]}.{args[1]}"]

        models.storage.save()

    def do_all(self, line):
        """Prints list of string representations of an object"""
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

    def emptyline(self):
        """handles the empty line condition
        """
        pass


if __name__ == '__main__':
    HBNBCommand().cmdloop()


"""
all BaseModel

obj_list = []

for v in dictionary.values()
    if (v.__class__.__name__ == "arg[0]")
        obj_list.append(str(v))

for v in dictionary.values()
    obj_list.append(str(v))

    print(obj)



"""
