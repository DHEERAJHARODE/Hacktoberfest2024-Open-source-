export default function Button({ text, onClick, style, type, children }) {
    return (
        <button type={type} className={style} onClick={onClick}>{
            text ? text : children
        }</button>
    )
}