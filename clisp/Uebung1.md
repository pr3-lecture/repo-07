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

(my-lengthR '(eins zwei (zwei (zwei drei) eins) drei vier)) -> 8  

```
> (defun my-lengthR (liste)
  (if (endp liste)
    0
    (if (listp (first liste))
      (+ (my-lengthR (first liste)) (my-lengthR (cdr liste)))
      (+ 1 (my-lengthR (cdr liste)))
    )
  )
)
MY-LENGTHR
> (my-lengthR '(eins zwei (zwei (zwei drei) eins) drei vier))
8
>
```

e) **Listen umkehren:** Schreiben eine Funktion `my-reverse` zum Umkehren einer Liste.  

(my-reverse '(eins zwei (zwei (zwei drei) eins) drei vier))  
-> (vier drei (zwei (zwei drei) eins) zwei eins)  

```
> (defun my-reverse (liste)
  (if (endp liste)
     '()
     (append (my-reverse (cdr liste)) (list (first liste)))
  )
)
MY-REVERSE
> (my-reverse '(eins zwei (zwei (zwei drei) eins) drei vier))
(VIER DREI (ZWEI (ZWEI DREI) EINS) ZWEI EINS)
>
```

f) **Geschachtelte Listen umkehren:** Schreiben eine Funktion `my-reverseR` zum Umkehren einer Liste.  

(my-reverseR '(eins zwei (zwei (zwei drei) eins) drei vier))  
-> (vier drei (eins (drei zwei) zwei) zwei eins)  

```
> (defun my-reverseR (liste)
  (if (endp liste)
    '()
    (if (listp (first liste))
      (append (my-reverseR (cdr liste)) (list (my-reverseR (first liste))))
      (append (my-reverseR (cdr liste)) (list (first liste)))
    )
  )
)
MY-REVERSER
> (my-reverseR '(eins zwei (zwei (zwei drei) eins) drei vier))
(VIER DREI (EINS (DREI ZWEI) ZWEI) ZWEI EINS)
>
```


## Aufgabe 2: ADT BinaryTree

Den ADT BinaryTree (binärer Suchbaum) kennen Sie aus ADS.

a) **Darstellung eines Binärbaums:** Uberlegen Sie, wie Sie mittels einer Liste einen Binärbaum darstellen
können.

```
Ein Binär-Baum kann in Lisp als miteinander verkettete Listen mit je drei Elementen realisiert werden.  
Dabei ist das erste Element der Liste immer die Wurzel, das zweite Element der linke Knoten und das  
dritte Element der rechte Knoten. Dieses Schema lässt sich dann in der Tiefe auch auf alle Unterbäume  
anwenden.

Beispiel:
                   M
            _______|_______
           /               \
           G               S
        ___|___         ___|___
       /       \       /       \
       E       H       Q       V
    ___|___         ___|___
   /       \       /       \
   A                       R

(M (G (E (A () ()) ()) (H () ())) (S (Q () (R () ())) (V () ())))
```

b) **Baumtraversierung:** Schreiben Sie 3 Funktionen zum Traversieren eines Binärbaums, bei der auch
die Knoteninhalte ausgegeben werden.

```
Lösung ...
```
