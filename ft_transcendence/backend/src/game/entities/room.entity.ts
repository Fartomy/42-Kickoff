
export default interface Room {
    //player socket id;
    player1 : string,
    player2? : string,
    //player id
    player1_id? :  number,
    player2_id? : number,
    is_private? : boolean,
}