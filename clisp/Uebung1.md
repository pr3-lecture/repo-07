# Übungsblatt 1

**Name:			Tobias Jünemann**  
**Matrikel-Nr.:	1428699**  


## Aufgabe 1: Methoden zur Listenmanipulation

a) **Elemente tauschen:** Schreiben Sie eine Funktion `rotiere`, die eine Liste als Argument erhält und eine
neue Liste zurückliefert, in der das vormals erste Element nun das letzte ist.  

(rotiere '(eins zwei drei vier)) -> (zwei drei vier eins)  

```
> (defun rotiere (liste)
    (append (cdr liste) (list (first liste)))
)
ROTIERE
> (rotiere '(eins zwei drei vier))
(ZWEI DREI VIER EINS)
>
```

b) **Element einfügen:** Schreiben Sie eine Funktion `neues-vorletztes`, die eine Liste als Argument erhält
und eine neue Liste zurückliefert, in der das vormals erste Element nun das letzte ist.  

(neues-vorletztes 'dreieinhalb '(eins zwei drei vier)) -> (eins zwei drei dreieinhalb vier)  

```
> (defun neues-vorletztes (element liste)
    (append (reverse (cdr (reverse liste))) (list element) (last liste))
)
NEUES-VORLETZTES
> (neues-vorletztes 'dreieinhalb '(eins zwei drei vier))
(EINS ZWEI DREI DREIEINHALB VIER)
>
```

c) **Länge einer Liste berechnen:** Schreiben Sie eine Funktion `my-length` zur Berechnung der Länge
einer Liste.  

(my-length '(eins zwei drei vier)) -> 4  

```
> (defun my-length (liste)
  (if (endp liste)
     0
     (+ 1 (my-length (cdr liste)))
  )
)
MY-LENGTH
> (my-length '(eins zwei drei vier))
4
>
```

d) **Länge einer geschachtelten Liste berechnen:** Schreiben Sie eine Funktion `my-lengthR` zur Berech-
nung der Länge einer Liste und aller eingeschachtelten Listen.

```
Lösung ...
```

e) **Listen umkehren:** Schreiben eine Funktion `my-reverse` zum Umkehren einer Liste.

```
Lösung ...
```

f) **Geschachtelte Listen umkehren:** Schreiben eine Funktion `my-reverseR` zum Umkehren einer Liste.

```
Lösung ...
```


## Aufgabe 2: ADT BinaryTree

Den ADT BinaryTree (binärer Suchbaum) kennen Sie aus ADS.

a) **Darstellung eines Binärbaums:** Uberlegen Sie, wie Sie mittels einer Liste einen Binärbaum darstellen
können.

```
Lösung ...
```

b) **Baumtraversierung:** Schreiben Sie 3 Funktionen zum Traversieren eines Binärbaums, bei der auch
die Knoteninhalte ausgegeben werden.

```
Lösung ...
```
