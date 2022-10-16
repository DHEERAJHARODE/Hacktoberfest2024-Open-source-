export default function TextField({type, value, onChange, children}){
    return(
        <>
            {children}
            <input type={type} value={value} onChange={onChange}/>
        </>
    )
}