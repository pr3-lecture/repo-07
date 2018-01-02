# Übungsblatt 2.1

**Name:			Tobias Jünemann**  
**Matrikel-Nr.:	1428699**  

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

## Aufgabe 1: BinaryTree

- **printLevelorder tree**  
Gibt Baum in Levelorder aus.

```
> (defun printLevelorder (tree)
  (if (endp tree)
    '()
    (remove nil
      (append
        (mapcar #'(lambda (x) (if (listp x) (car x) x)) tree)
        (printLevelorder (mapcan #'(lambda (x) (if (null x) '() (if (listp x) (list (cadr x) (caddr x)) '()))) tree))
      )
    )
  )
)
PRINTLEVELORDER
> (printLevelorder '(13 (7 (5 (1 () ()) ()) (8 () ())) (19 (17 () (18 () ())) (22 () ()))))
(13 7 19 5 8 17 22 1 18)
>
```
	   