#ifndef CHUNK_H
#define CHUNK_H
#define CHUNK_COLS 20
#define CHUNK_ROWS 10

typedef struct Chunk{
    int mapa[CHUNK_ROWS][CHUNK_COLS];
    struct Chunk *proximo;
} Chunk;

extern char *chunks[20][CHUNK_ROWS];

Chunk *criar_chunks(int indice);
void destruir_chunk(Chunk *c);

#endif