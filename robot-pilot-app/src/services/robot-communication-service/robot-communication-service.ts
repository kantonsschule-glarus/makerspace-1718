import { Injectable } from '@angular/core';
import { Http } from '@angular/http';
import 'rxjs/add/operator/map';

@Injectable()
export class RobotCommunicationService {
    robotUrl: string = "http://robot.ing.gl";

  constructor(public http: Http) {;}

  setSpeedLeftWheel(value: number):void{
      this.sendWheelVelocity(value,"set-left-wheel-velocity");
  }

    setSpeedRightWheel(value: number):void{
        this.sendWheelVelocity(value,"set-right-wheel-velocity");
    }

    sendWheelVelocity(value: number, serviceName: string){
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
