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
Lösung ...
```

- **size tree**  
Ermittelt die Anzahl der Knoten im Baum.

```
> (defun size (liste)
  (if (endp liste)
    0
    (if (listp (first liste))
      (+ (size (first liste)) (size (cdr liste)))
      (+ 1 (size (cdr liste)))
    )
  )
)
SIZE
> (size '(M (G (E (A () ()) ()) (H () ())) (S (Q () (R () ())) (V () ()))))
9
>
```

- **height tree**  
Ermittelt die Höhe des Baums.

```
Lösung ...
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
> (defun isEmpty (liste)
  (if (endp liste)
    T
    nil
  )
)
ISEMPTY
> (isempty '())
T
> (isempty '(M () ()))
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