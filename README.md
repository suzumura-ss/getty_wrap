getty_wrap
===============

Drop keybard events for /sbin/getty.

Make and Install
----------------

        $ make
        $ sudo make install # install to /usr/sbin/local
        

How to use
----------

Modify /etc/initab.

        1:2345:respawn:/sbin/getty --noclear 38400 tty1
        
        to 
        
        # 1:2345:respawn:/sbin/getty --noclear 38400 tty1
        1:2345:respawn:/usr/local/sbin/getty_wrap /sbin/getty --noclear 38400 tty1
