attribute taintedness 
    context reference char * 
    oneof untainted, tainted 
    annotations
        tainted reference ==> tainted
        untainted reference ==> untainted 
    transfers
        tainted as untainted ==> error "Possibly tainted storage used where untainted required." 
    merge
        tainted + untainted ==> tainted defaults
    reference ==> tainted literal ==> untainted null ==> untainted
end