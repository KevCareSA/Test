#!/usr/bin/python3

import cmd


class Interpreter(cmd.Cmd):
    """Simple command processor example."""

    prompt = "(hbnb) "

    def do_EOF(self, line):
        """Handles EOF condition by exiting the Shell"""
        print()
        return True

    def do_quit(self, line):
        """Exit the shell\n"""
        return True

    def emptyline(self):
        pass


if __name__ == '__main__':
    Interpreter().cmdloop()
