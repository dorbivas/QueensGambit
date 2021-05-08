   ___   _   _  ___  ___  _  _  ___    ___    _    __  __  ___  ___  _____ 
  / _ \ | | | || __|| __|| \| |/ __|  / __|  /_\  |  \/  || _ )|_ _||_   _|
 | (_) || |_| || _| | _| | .` |\__ \ | (_ | / _ \ | |\/| || _ \ | |   | |  
  \__\_\ \___/ |___||___||_|\_||___/  \___|/_/ \_\|_|  |_||___/|___|  |_|  
                                                                           

DECRIPTION:


/////////////////////////////////////////////////////////////////////////////
TODO's:

General:
    must add Free functions for all the allocations (!!!)
Q3:
    check all ListCell functions 
    check path builder
    check print path
    fund a better way to orginize the files - for easier future fixes

/////////////////////////////////////////////////////////////////////////////
CHANGES:
{{in this format:}}
Name - date (dd/mm/yy hh:mm)
****************************************************************************
list between the * rows all the changes
****************************************************************************

Idan 08/05/21 16:15 
/***************************************************************************
1) IntToChar functions is returning the coordinate value example (A1 => 0,0)

2) Q1 changed from (**chessPosArray) type to (***chessPosArray) in order for better use in Q3

3) The board size is fully modular just need to change the BOARD_SIZE value in Util.h

4) the void CreateListCell function was replaced with
CreateListCellnotvoid  (*we need a new name*) that returns the new List Cell
due to error issues.

minor changes:
1)added check alloc in some locations

2)moved all Q3.c functions to Q3.h
*****************************************************************************