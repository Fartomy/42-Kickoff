import { io } from "socket.io-client";

export function gameSocket() {
  return io(`${process.env.NEXT_PUBLIC_SOCKET_URL}/game`)
}
