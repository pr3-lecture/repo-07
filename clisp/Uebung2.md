# Übungsblatt 2

**Name:			Tobias Jünemann**  
**Matrikel-Nr.:	1428699**  


## Aufgabe 1: BinaryTree

Im ersten Übungsblatt haben Sie bereits die 3 bekannten Traversierungs-Arten für Binäre Bäume geschrie-  
ben.  
Jetzt soll ein Binärer Suchbaum mit einer absoluten Ordnung (nehmen Sie dazu einfach an, dass int-Werte  
in Knoten gespeichert werden) implementiert werden, der folgende Funktionen bereitstellt:

- **insert tree val**  
Fügt **val** in den Baum **tree** ein und gibt als Ergebnis den  
ergänzten Baum zurück. Am besten wird dabei ein neuer Baum  
erzeugt.

```
Lösung ...
```

- **insert tree filename**  
Fügt die int-Werte, die in der Datei stehen in den Baum ein.

```
Lösung ...
```

- **contains tree val**  
Testet, ob **val** im Baum vorhanden ist.

```
> (defun contains (tree val)
  (if (endp tree)
    nil
    (if (listp (first tree))
      (or (contains (first tree) val) (contains (cdr tree) val))
      (if (eql (first tree) val)
        T
        (contains (cdr tree) val)
      )
    )
  )
)
CONTAINS
> (contains '(13 (7 (5 (1 () ()) ()) (8 () ())) (19 (17 () (18 () ())) (22 () ()))) 18)
T
> (contains '(13 (7 (5 (1 () ()) ()) (8 () ())) (19 (17 () (18 () ())) (22 () ()))) 99)
NIL
>
```

- **size tree**  
Ermittelt die Anzahl der Knoten im Baum.

```
> (defun size (tree)
  (if (endp tree)
    0
    (+ 1 (size (cadr tree)) (size (caddr tree)))
  )
)
SIZE
> (size '(13 (7 (5 (1 () ()) ()) (8 () ())) (19 (17 () (18 () ())) (22 () ()))))
9
>
```

- **height tree**  
Ermittelt die Höhe des Baums.

```
> (defun height (tree)
  (if (endp tree)
    0
    (+ 1 (max (height (cadr tree)) (height (caddr tree))))
  )
)
HEIGHT
> (height '(13 (7 (5 (1 () ()) ()) (8 () ())) (19 (17 () (18 () ())) (22 () ()))))
4
>
```

- **getMax tree**  
Liefert das größte Element im Baum.

```
Lösung ...
```

- **getMin tree**  
Liefert das kleinste Element im Baum.

```
Lösung ...
```

- **remove tree val**  
Entfernt **val** aus dem Baum und gibt als Ergebnis den geänderten  
Baum zurück.  
Wenn ein innerer Knoten gelöscht wird, dann erstetzen Sie ihn  
durch den kleinsten Knoten in dessen rechtem Teilbaum.

```
Lösung ...
```

- **isEmpty tree**  
**true** genau dann, wenn der Baum leer ist.

```
> (defun isEmpty (tree)
  (if (endp tree)
    T
    nil
  )
)
ISEMPTY
> (isempty '())
T
> (isempty '(13 () ()))
NIL
>
```

- **addAll tree otherTree**  
Fügt alle Elemente des übergebenen Baums (**otherTree**) in
den aktuellen Baum **tree** ein.

```
Lösung ...
```

- **printLevelorder tree**  
Gibt Baum in Levelorder aus.

```
Lösung ...
```

Beschreiben Sie (im Kommentar), welche Ergebnisse herauskommen.  

Achten Sie bei der Implementierung darauf, dass der Code möglichst kompakt und gut verständlich ist (dass  
er korrekt ist, versteht sich von selbst); Effizienz ist zweitrangig. Nutzen Sie Rekursion!.  

Uberlegen Sie, wie man die Eingabe möglichst komfortabel gestalten kann. D.h. wie könnte eine "Benutzer-  
schnittstelle" aussehen.  
  
  
```
Baum zum Testen:
                   13
            _______|_______
           /               \
           7               19
        ___|___         ___|___
       /       \       /       \
       5       8       17      22
    ___|___         ___|___
   /       \       /       \
   1                       18

(13 (7 (5 (1 () ()) ()) (8 () ())) (19 (17 () (18 () ())) (22 () ())))
```