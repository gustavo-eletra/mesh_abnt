idf_component_register(SRCS "main.c" "uart.c" "mesh_network.c" "utils.c" "protocols/abnt.c" "events.c" "./msgpack/byte_reader.c" "./msgpack/lexer.c"
                 INCLUDE_DIRS "." "./msgpack" "./protocols")
