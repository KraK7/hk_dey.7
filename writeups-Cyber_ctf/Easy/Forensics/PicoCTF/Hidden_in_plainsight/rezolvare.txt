Problema ne spune clar ca avem o imagine de tip .jpg obsinuita. dar ceva din vedere e ascuns in interiorul fisierului.
Noi trebuie sa descoperim o sarcina utila ascunsa si sa extragem flagul

Rezolvare:

1. vedem ca ne da o idee precum sa descarcam imaginea si sa citim metadatele
   Noi il descarcam, deschidem imaginea cu comanda:

                                            xdg-open img.jpg

   Si observam o imagine smechera, ceva de codare, cu un stil negru cu multe coduri si numere, analizand atent nu avem nici-o informatie


2. Sa dam seama ce trebuie sa facem la imagine e sa folosim comanda:

                                       strings img.jpg | head

   Ne afiseaza asta:

JFIF
c3RlZ2hpZGU6Y0VGNmVuZHZjbVE9
 $.' ",#
(7),01444
'9=82<.342
!22222222222222222222222222222222222222222222222222
$3br
%&'()*456789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz
	#3R
&'()*56789:CDEFGHIJSTUVWXYZcdefghijstuvwxyz
koZ9
cPp]
2UG$
;3/BNq]
stU*
,A V
<jZ9sb]bW
;w 31W
*B\!l
 .....


Nimic important aici, si asa am decis sa folosim si comanda:

                                                 exiftool img.jpg
Si ne afiseaza:

ExifTool Version Number         : 13.25
File Name                       : img.jpg
Directory                       : .
File Size                       : 74 kB
File Modification Date/Time     : 2025:11:27 14:36:04+02:00
File Access Date/Time           : 2025:11:27 14:36:27+02:00
File Inode Change Date/Time     : 2025:11:27 14:36:13+02:00
File Permissions                : -rw-rw-r--
File Type                       : JPEG
File Type Extension             : jpg
MIME Type                       : image/jpeg
JFIF Version                    : 1.01
Resolution Unit                 : None
X Resolution                    : 1
Y Resolution                    : 1
Comment                         : c3RlZ2hpZGU6Y0VGNmVuZHZjbVE9
Image Width                     : 640
Image Height                    : 640
Encoding Process                : Baseline DCT, Huffman coding
Bits Per Sample                 : 8
Color Components                : 3
Y Cb Cr Sub Sampling            : YCbCr4:2:0 (2 2)
Image Size                      : 640x640
Megapixels                      : 0.410
            


Observam ca la comment avem un sir ciudat asa cum putem spune, si se vede cu ochiul liber ca ascunde mesaj secret

                                         Comment                         : c3RlZ2hpZGU6Y0VGNmVuZHZjbVE9

3. Dupa analizele mele observ ca e codat in Base64. si asa am decis sa il decodam mesajul acela cu urmatoarea comanda:
 
                                              echo -n "c3RlZ2hpZGU6Y0VGNmVuZHZjbVE9" | base64 -d 

    Si ne afiseaza: 
   
                                               steghide:cEF6endvcmQ=                                                                                                                               

   Dupa cum vedem ne-a decodificat si ne-a afisat: steghide:cEF6endvcmQ=

4. mesajul e decodificat dar nu tot, vedem ca a mai ramas o parte sa decodificam si tot in base64, 
   folosim iar comanda aceea ca ceea din interioara:

                                        echo -n "cEF6endvcmQ=" | base64 -d

    Ne afiseaza:

                                        pAzzword

    Ne gandim ce vrea sa ne spuna acel cod decodificat fiind spus cu "pAzzword".
    Si ne dam seama ca trebuie sa extragem din imagine ceva, dar nu stim ce, tinand cont ca daca extragem ne va cere si parola,
    iar parola ar fi aceea care l-am gasit "pAzzword", asa ca trebuie sa folosim unelte mai puternice de extragerea fisierelor din imagine.
 

5. unealta pe care il putem folosi ar fi steghide.
                    
                                                        steghide extract -sf img.jpg

   Ne afiseaza:
 
  Introduceti parola: pAzzword                         ----> acolo introducem parola pe care l-am aflat
  
 Dupa ce dai enter, ne afiseaza asta:
   scrie data extrasa la "flag.txt".

Si acum avem fisierul flag.txt


6. folosim comanda: cat flag.txt si ne afiseaza flag-ul:

picoCTF{h1dd3n_1n_1m4g3_871ba55} ----> flag gasit


!!!! Bonus !!!!!


steghide ascunde sau extrage fișiere din imagini/audio, folosind parametri precum -cf, -ef, -sf 
pentru a specifica ce fișier acoperă, ce fișier e ascuns și de unde să extragi. 

!!!! BONUS !!!!



flag: picoCTF{h1dd3n_1n_1m4g3_871ba55}


Succes !!! :)))

