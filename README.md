# Mini-shell **Vagón-sh**
Mini proyecto de  la asignatura Sistemas Operativos (SO). La shell debe reconocer expresiones como `$ ls -lAh | wc` y `$ ls -lAh > salida.txt`.

## Dependencias
Para instalar la **Vagon-sh** hay que cumplir las siguientes dependencias (cabe aclarar que en root): `make`, `clang` y `git`.

### Arch (y derivadas)
~~~sh
# pacman -Sy make clang git
~~~

### Ubuntu (y derivadas)
~~~sh
# apt install make clang-12 git
~~~

## Instalación y ejecución
~~~sh
$ git clone https://github.com/AxzelBC/Mini-shell.git
$ cd Mini-shell
$ make
$ ./vagon-sh
~~~

## Desinstalación
Se ejecuta el comando dentro de la carpeta /Mini-shell

~~~sh
$ make clean
~~~
