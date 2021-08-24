/*!
 * \file
 * \brief Input/output include file.
 * \author d3phys
 * \date 24.08.2021
*/
#ifndef IO_H_
#define IO_H_
#include <stdio.h>


/*!
 * \brief ASCII colors enum
*/
enum colors {
    NOTHING = 0,
    RESET,
    RED,
    GREEN,
    YELLOW,
    BLUE,
};

/*!
 * \brief Sets console color
 *
 * Function sets ASCII text and background console color
 *
 * \param  text       Text color
 * \param  background Background color
 *
 * \return 
 * - Error:   negative value.
 * - Success: positive value.
 *
 * \bug 
 * ASCII reset symbol is the same for text and background. 
 * - If you use set_color(RESET) both text and background will reset.
 * - Try to use set_color(NOTHING, RED) if you don't want to change text color. 
 *
 * \code
 *
 * set_color(RED);           // RED console text color
 * set_color(YELLOW, RESET); // Default console text and background color
 *
 * \endcode
*/
int set_color(colors text = NOTHING, colors background = NOTHING);

/*!
 * \brief Gets a string from a stream.
 *
 * Function changes last symbol that has been read to '\0'.
 *
 * \param[out] buffer Storage location for data
 * \param[in]  size   Maximum number of characters to read
 * \param[in]  stream Pointer to file structure
 *
 * \return 
 * - The number of characters has been read.
 * - -1 If storage location is smaller than thr stream line size.
 *
 * \warning 
 * Don't forget that the number of characters has been read will be 
 * less by 1 than the size parameter due to the '\0'. 
 *
 * \code
 *
 * if (getl(buffer, 10, stdin) == -1)
 *      printf("Error!!!");
 *
 * if (strcmp(buffer, "hello"))
 *      printf("Hello my dear friend!");
 *
 * \endcode
*/
int getl(char *buffer, const size_t size, FILE *stream);


#endif // IO_H_
