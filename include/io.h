/*!
 * \file
 * \brief Input/output include file.
*/
#ifndef IO_H_
#define IO_H_
#include <stdio.h>

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
