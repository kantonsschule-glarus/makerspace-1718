import { Injectable } from '@angular/core';
import { Http } from '@angular/http';
import 'rxjs/add/operator/map';

@Injectable()
export class RobotCommunicationService {
    robotUrl: string = "http://robot.ing.gl";

  constructor(public http: Http) {;}

  setLeftWheelVelocity(value: number):void{
      this.sendWheelVelocity(value,"set-left-wheel-velocity");
  }

    setRightWheelVelocity(value: number):void{
        this.sendWheelVelocity(value,"set-right-wheel-velocity");
    }

    private sendWheelVelocity(value: number, serviceName: string){
        console.log("calling service :"+serviceName+" with value=",value);
        this.http.get(this.robotUrl + "/"+serviceName+"?value="+value).subscribe(
            (data) => {
                console.log(data);
            },
            (err) => {
                console.error(err);
            },
            () => {}
        );
    }
}
