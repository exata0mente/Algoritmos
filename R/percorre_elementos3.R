percorre_elementos3 <- function(conjunto){
  #recebe um conjunto por parametro
  resposta <- vector()
  elemento_base <- conjunto[1]
  subconjunto <- conjunto[-1]
  for(i in seq_along(subconjunto))
    print(paste(elemento_base,subconjunto[i],sep=""))
  #   resposta <- c(resposta,paste(elemento_base,subconjunto[i],sep=""))
  # resposta
}