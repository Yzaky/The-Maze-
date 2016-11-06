#ifndef _Field_H
#define _Field_H
/** @brief Defining the Field structure , which takes the dimensions X and Y and an 2D Array */
typedef struct
{   /**Dimension X of the field*/
	int dimX;
	/** Dimension Y of the field */
	int dimY;
	/**Array that uses both of the dimensions X and Y in order to allocate the field with the dimensions given */
	char **tab;
} Field ;
/** @brief This procedure initialize the field (map) and allocate each case's memory depending on the dimensions
    @param Field pointer on the structure
    @param file that contains the map to draw in the tab
 */

void fieldInit(Field *,const char file[]);
/** @brief Sets free the space allocated for the field in the previous Procedure.
    @param Field pointer on the Structure
*/


void fieldFree(Field *);
/** @brief Checks and verify that a case's coordinates are valid
    @param Field pointer on the Structure
    @param x int the position on the abscissa axe
    @param y int the position on the ordinate axe
    @return true or false
*/
int fieldPosValid(const Field *, const int x, const int y);
/** @brief Returns the case pointed by the coordinates given in the parametres
    @param Field pointer on the Structure
    @param x int the position on the abscissa axe
    @param y int the position on the ordinate axe
    @return the tab[x][y] after verifying it's existence.
    */

const char fieldGetXY(const Field *, const int x, const int y);
/** @brief Puts the value given in the parametres in the case indicated
    @param x int the position of the case on the abscissa axe
    @param y int the position of the case on the ordinate axe
    @param val char the value that we want to put in the case
    */

void fieldSetXY(const Field *, const int x, const int y, const char val);
/** @brief This function returns the field case's position on the abscissa axe
    @param Field pointer on the Structure
    @return x int the dimension of the field on the abscissa axe
    */

const int fieldGetDimX(const Field *);

/** @brief This function returns the field case's position on the ordinate axe
    @param Field pointer on the Structure
    @return y int the dimension of the field on the ordinate axe
    */
const int fieldGetDimY(const Field *);

#endif
