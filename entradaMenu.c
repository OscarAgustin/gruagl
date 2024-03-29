/*	Grua 

	C.A.D. 						Curso 2008-2009
 	
	Codigo base para la realización de las practicas de CAD

	modulo entradaMenu.c
	Gestion de eventos de menu
=======================================================
	J.C. Torres 
	Dpto. Lenguajes y Sistemas Informticos
	(Univ. de Granada, SPAIN)

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details 
 http://www.gnu.org/copyleft/gpl.html

=======================================================
Queda prohibido cobrar canon por la copia de este software

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>                   // Libreria de utilidades de OpenGL
#include "grua.h"



// Nota: Los acentos han sido suprimidos en la documentacion por compatibilidad
// con las version usada de doxygen. Las letras ñ se han sustituido por "ny"


/** 			void seleccionMenu( int opcion )

Este procedimiento es llamado por glut cuando ocurre un evento de seleccion de una 
opcion del menu. El parametro contiene el identificador de la opcion
 
 Cuando se anyanden opciones se debe anyadir un case en el switch para esa opcion.
 
 **/
 void seleccionMenu( int opcion )
{
   gluiSetCanvasWindow();
   gluiOutput( "");			// Borra el mensaje actual
   switch ( opcion )
   {   
   case PASEAR:
   	estado= paseando;
   	VISTA_PERSPECTIVA= 1; 			// Fija perspectiva y recalcula proyeccion
	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
	fijaProyeccion();
	gluiOutput( "Se ha cambiado a vista 3D");	// Nuestra mensaje en interfaz
	break;
   case DESDEARRIBA: 
   	estado = vistaArriba; 
   	VISTA_PERSPECTIVA= 0; 			// Fija proyeccion paralela y recalcula proyeccion
	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
	fijaProyeccion();
	gluiOutput( "Se ha cambiado a vista 2D"); 	// Nuestra mensaje en interfaz
   	break;
        
   case PONERCAJAS:
       estado = ponerCajas;
       VISTA_PERSPECTIVA= 0;
       glMatrixMode(GL_PROJECTION);
           glLoadIdentity();
       fijaProyeccion();
       gluiOutput( "Se ha cambiado a poner cajas");
               
    break;
   case PINTARCAJA:
        estado = pintandoCajas;
        gluiOutput( "Se ha cambiado a colorear");
    break;
   case ENGANCHAR:
        estado = enganchando;
        gluiOutput( "Se ha cambiado a enganchar");
    break;
   case DESENGANCHAR:
        estado = soltando;
        soltarCaja();
        gluiOutput( "Se ha cambiado a soltar");
    break;
   case ROTARCAJA:
        estado = rotandoCaja;
        gluiOutput( "Se ha cambiado a rotar caja");
    break;
   case MOVERCAJA:
        estado = moviendoCaja;
        gluiOutput( "Se ha cambiado a mover caja");
    break;
       
   case SALIR:
   	  exit(0);      // Salir del programa
   }
	gluiPostRedisplay(); 	// Si se ha modificado algo que cambia el estado del
				// modelo se debe actualizar la pantalla
}


/** 

Crea el menu.pop-up de la ventana grafica

Este procedimiento debe llamarse para crear el menu pop-up de glut (normalmente al inicializar el
programa).
 
Para anyadir opciones al menu anyadir una llamada glutAddMenuEntry e incluir valores del tipo enumerado en la declaracion de opciones_menu.

 **/
void CreaMenu()
{

   	menu = glutCreateMenu( seleccionMenu );

    	glutAddMenuEntry("Vista 2D",DESDEARRIBA);	// Cada llamada lleva el nombre de la oopcion 
    	glutAddMenuEntry("Pasear",PASEAR);		// y el identificador que se devuelve al usarla
        glutAddMenuEntry("Colocar Caja", PONERCAJAS);
        glutAddMenuEntry("Colorear", PINTARCAJA);
        glutAddMenuEntry("Enganchar", ENGANCHAR);
        glutAddMenuEntry("Soltar", DESENGANCHAR);
        glutAddMenuEntry("Mover", MOVERCAJA);
        glutAddMenuEntry("Rotar", ROTARCAJA);
   	glutAddMenuEntry( "Exit", SALIR );

   	glutAttachMenu( GLUT_RIGHT_BUTTON );	// Indica que el boton derecho abre el menu.

}

