const Button = ({ children, onClick, className, variant = "primary" }) => {
    const baseClasses = `py-2 px-4 rounded-md font-semibold focus:outline-none transition duration-300`;
    const variantClasses = variant === "primary"
      ? "bg-blue-600 text-white hover:bg-blue-700"
      : "bg-gray-300 text-gray-900 hover:bg-gray-400";
  
    return (
      <button className={`${baseClasses} ${variantClasses} ${className}`} onClick={onClick}>
        {children}
      </button>
    );
  };
  
  export { Button };
  