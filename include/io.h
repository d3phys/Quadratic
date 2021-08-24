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
enum color {
    RED = 1,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
};

/*!
 * \brief Sets console text color
 *
 * Function sets ASCII text console color
 *
 * \param  text Text color
 *
 * \return 
 * The same as printf() function
*/
int set_text_color(color text);

/*!
 * \brief Sets console background color
 *
 * Function sets ASCII background console color
 *
 * \param  background Background color
 *
 * \return 
 * Negative value in case of error 
*/
int set_back_color(color background);

/*!
 * \brief Resets console color settings
 *
 * \warning Function resets both background and text color settings
 *
 * \return 
 * Negative value in case of error 
*/
int reset_color(); 

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
 * if (strcmp(buffer, "hello") == 0)
 *      printf("Hello my dear friend!");
 *
 * \endcode
*/
int getl(char *buffer, const size_t size, FILE *stream);


#endif // IO_H_
