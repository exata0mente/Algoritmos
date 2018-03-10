combina_elementos <- function(conjunto = LETTERS[1:4]){
  
  resultado <- conjunto
  j <- 1
  while(j < length(conjunto)){ #ELEMENTOS BASE
    k <- j + 1
    while(k <= length(conjunto)){#ELEMENTOS VARIAVEIS
      # resultado <- c(resultado,percorre_elementos3(conjunto[j:k]))
      print(percorre_elementos3(conjunto[j:k]))
      k <- k +1
    }
    j <- j + 1
  }
  #resultado <- resultado[order(resultado)]
  resultado
}