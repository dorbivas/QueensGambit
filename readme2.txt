   ___   _   _  ___  ___  _  _  ___    ___    _    __  __  ___  ___  _____ 
  / _ \ | | | || __|| __|| \| |/ __|  / __|  /_\  |  \/  || _ )|_ _||_   _|
 | (_) || |_| || _| | _| | .` |\__ \ | (_ | / _ \ | |\/| || _ \ | |   | |  
  \__\_\ \___/ |___||___||_|\_||___/  \___|/_/ \_\|_|  |_||___/|___|  |_|  
                                                                           

Idan Oren 209007921 
Dor Bivas 315557850

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
CHANGES:
{{in this format:}}
Name - date (dd/mm/yy hh:mm)
****************************************************************************
list between the * rows all the changes
****************************************************************************

Idan 09/06/21 21:00
****************************************************************************
1) Q6 is checked the work has done

2) Q5 and Q6 needs to be added to Q7 switch case

****************************************************************************


Idan + Dor 29/05/21 23:15
****************************************************************************
1) finished Q5 but better testing results will come after Q6 is finished

2) Q6 finished read from file alogirism although testing wasn't performed

3) Q6.h and Q6.c were added

4) Work around is still needed, mostly for small TODO tasks
****************************************************************************


Dor 28/05/21 17:41
****************************************************************************
1) Q7 improvments displaying path and looping the menu

2) Q7.h added

3) util.c isValidInput added
****************************************************************************


Dor 24/05/21 21:41
****************************************************************************
1) Q4.h - findKnightPathCoveringAllBoardRec removed.. ("rec" replace it)

2) Q7.c added menu Q1-4 covered in 

3) handeling minors TODO's

4) much TODO's left inside Q7
****************************************************************************


Dor 21/05/21 17:18
****************************************************************************
1) Massive Load of changes!!! /*TODO CHANGE*/

2) Q3 Q1 free funcs added, free visit Matrix and valid Knight moves board.

3) Commentary, notes and cleanning junk funcs.

4) ordering idan unordered funcs.

5) handeling minors TODO's
****************************************************************************


Idan 21/05/21 17:00
****************************************************************************
1) Massive changes!!!

2) Q3 and Q4 works comletely.

3) changed Q1 add create valid moves board for quick path finding in Q4

4) added main.c file for testing and integrations.

5) added free for all the structures in the code. 
****************************************************************************


Dor 15/05/21 20:58
****************************************************************************
1) Making Q4 sol ,adding Q4.h

2) adding Q4 utilty to Util.c/h /
****************************************************************************


Idan 15/05/21 20:23
****************************************************************************
1) In Q3, switched all the visitMatrix signatures from (***) to (**) due to an error in isVisited

2) Added chessPosSetter in Utill.c for easy and secure setting

3) Fixed a bug where next in ListCell was not defined correctly (_treeNodeListcell instead of _treeNodeListCell)

4) Finished Q3 testing
****************************************************************************


Idan 08/05/21 16:15 
****************************************************************************
1) IntToChar functions is returning the coordinate value example (A1 => 0,0)

2) Q1 changed from (**chessPosArray) type to (***chessPosArray) in order for better use in Q3

3) The board size is fully modular just need to change the BOARD_SIZE value in Util.h

4) the void 
function was replaced with
CreateListCellnotvoid  (*we need a new name*) that returns the new List Cell
due to error issues.

minor changes:
1)added check alloc in some locations

2)moved all Q3.c functions to Q3.h
*****************************************************************************


