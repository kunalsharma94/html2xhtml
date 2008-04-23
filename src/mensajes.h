/***************************************************************************
 *   Copyright (C) 2007 by Jesús Arias Fisteus   *
 *   jaf@it.uc3m.es   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*
 * mensajes.h
 *
 * (Jes�s Arias Fisteus)
 *
 * macros y funciones para imprimir mensajes en stderr
 *
 * todos los m�dulos del proyecto pueden usarlo, simplemente
 * incluyendo este fichero
 *
 * para versiones definitivas de proyecto, en que no
 * se desee la salida de estos mensajes, basta con
 * no definir la variable MSG_DEBUG o definir la
 * variable NO_DEBUG, y las llamadas no generar�n 
 * absolutamente ning�n c�digo compilado
 *
 */

#ifndef MENSAJES_H
#define MENSAJES_H

#include <stdio.h>


#ifdef NO_DEBUG
#undef MSG_DEBUG
#endif


extern int num_warning;
extern int num_inform;
extern int parser_num_linea;

/* handler de errores a declarar en el m�dulo de control */
void exit_on_error(char *msg);


#define EXIT(msg)   {exit_on_error(msg);}

#define WARNING(msg) {fprintf(stderr,"WARNING(%s,%d)[l%d]: %s\n",__FILE__,\
                      __LINE__,parser_num_linea,msg);\
                      num_warning++;}



/* 
 * los siguientes mensajes aparecen s�lo si se compila
 * con la macro MSG_DEBUG definida y NO_DEBUG sin definir.
 *
 */

#ifdef MSG_DEBUG
/* DEBUG */



#define INFORM(msg) {fprintf(stderr,"INFORM(%s,%d)[l%d]: %s\n",__FILE__,\
                      __LINE__,parser_num_linea,msg);\
                     num_inform++;}


#define WARNING_T(token)  \
           {fprintf(stderr,"WARNING (%s,%d)[l%d]: token %s no esperado\n",\
                      __FILE__,__LINE__, parser_num_linea,\
                      htmlTokenToString(token)); \
            num_warning++;}

#define DEBUG(msg)    {fprintf(stderr,"DEBUG (%s,%d)[l%d]: %s\n",__FILE__,\
                              __LINE__, parser_num_linea,msg );}


#define EPRINTF(format)                 fprintf(stderr,format)   
#define EPRINTF1(format,arg1)           fprintf(stderr,format,arg1)   
#define EPRINTF2(format,arg1,arg2)      fprintf(stderr,format,arg1,arg2)   
#define EPRINTF3(format,arg1,arg2,arg3) fprintf(stderr,format,arg1,arg2,arg3)   

#else
/* NO_DEBUG */

#define INFORM(msg)                         ;
#define WARNING_T(token)                    ;
#define DEBUG(msg)                          ;
#define EPRINTF(format)                     ;
#define EPRINTF1(format,arg1)               ;
#define EPRINTF2(format,arg1,arg2)          ;
#define EPRINTF3(format,arg1,arg2,arg3)     ;

#endif


/*
 * imprime el total de warnings,... generados
 *
 */
void mensajes_fin(void);



#endif
