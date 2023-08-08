#!/usr/bin/python3

"""
This module is the cmd interface for the console

authors: Bradley Gilden && Lebohang (KevCare) Mokobane
date: 07/08/2023
"""


import cmd


class HBNBCommand(cmd.Cmd):
    """Simple command processor example."""

    prompt = "(hbnb) "

    def do_EOF(self, line):
        """Handles EOF signal by exiting the Shell
        """
        print()
        return True

    def do_quit(self, line):
        """Quit command to exit the program
        """
        return True

    def emptyline(self):
        """handles the empty line condition
        """
        pass


if __name__ == '__main__':
    HBNBCommand().cmdloop()
