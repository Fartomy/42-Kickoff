import {Vector2d} from "@/entities/vector2d.entity";

export default class Player {

    public width: number;
    public height : number;
    public position : Vector2d;
    public target : number;
    public speed : number;
    public color : string;
    public score : number;
    public key : number;

    constructor(
        width: number, height : number,
        position : any, target : number,
        speed: number, color: string) {
        this.width = width;
        this.height = height;
        this.position = position;
        this.target = target;
        this.speed = speed;
        this.color = color;
        this.score = 0;
        this.key = 0;
    }

    moveDown() {
        this.key = 1;
    }

    moveUp() {
        this.key = 2;
    }

    move() {
        setTimeout(() => {
            if (this.key == 1)
            {
                this.speed += 0.1;
                this.target += this.position.Y + this.speed;
            }
            else if(this.key == 2)
            {
                this.speed += 0.1;
                this.target -= this.position.Y + this.speed;
            }
        });
    }
}