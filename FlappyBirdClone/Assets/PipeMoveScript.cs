using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PipeMoveScript : MonoBehaviour{
    public float moveSpeed = 5;
    public float deadZone = -45;

    void Start(){
        
    }
    void Update(){
        if (transform.position.x > deadZone){
            Destroy(gameObject);
        }
    }
}
