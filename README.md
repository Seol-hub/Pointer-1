## Source Code

## Struct
typedef struct std{}; <br/>

## intput
std * list = NULL, * prev = NULL, * p = NULL; <br/>
p = (std*)malloc(sizeof(std)); <br/>

p->link = NULL; <br/>
if(!list) list = p; <br/>
else prev->link = p; <br/>
prev = p; <br/>

## output
p = list; <br/>
while(p) { <br/>
p = p->link; <br/>
} <br/>

## free node
std * pa = list <br/>
while(pa){ <br/>
  list = list->link; <br/>
  free(pa); <br/>
  pa = list; <br/>
}
