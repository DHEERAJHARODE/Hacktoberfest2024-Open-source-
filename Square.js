import React from 'react'

function Square({id,className,state}) {
  return (
    <div className={`squarec ${className} ${state==='X' ? "x-color" : "o-color"}`} id={id} >{state}</div>
  )
}

export default Square